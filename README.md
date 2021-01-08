Deutsche eMark Core
===================

https://deutsche-emark.org/

License
-------

eMark Core is released under the terms of the MIT license. See [COPYING](COPYING) for more
information or see https://opensource.org/licenses/mit-license.php.

Intro
-----

Deutsche eMark (DEM) is an experimental digital currency that enables instant payments to
anyone, anywhere in the world. Deutsche eMark uses peer-to-peer technology to operate
with no central authority: managing transactions and issuing money are carried
out collectively by the network. eMark Core is the name of open source
software which enables the use of this currency.

For more information, as well as an immediately usable, binary version of
the eMark Core software, see https://deutsche-emark.org/filebase/, or read the
[original whitepaper](https://deutsche-emark.org/de/whitepaper/).

Development Process
-------------------

The `master` branch is regularly built (see `doc/build-*.md` for instructions) and tested, but it is not guaranteed to be
completely stable. [Tags](https://github.com/emarkproject/eMark/tags) are created
regularly from release branches to indicate new official, stable release versions of eMark Core.

Feature branches are created when there are major new features being
worked on by several people.

Change log can be found in [CHANGELOG.md](CHANGELOG.md).


Testing
-------

Testing and code review is the bottleneck for development; we get more pull
requests than we can review and test on short notice. Please be patient and help out by testing
other people's pull requests, and remember this is a security-critical project where any mistake might cost people lots of money.

### Manual Quality Assurance (QA) Testing

Changes should be tested by somebody other than the developer who wrote the
code. This is especially important for large or high-risk changes. It is useful
to add a test plan to the pull request description if testing the changes is
not straightforward.
